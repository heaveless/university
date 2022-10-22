import os
import json
import uuid

from flask import Flask, render_template, request, jsonify
from flask_assets import Environment, Bundle
from waitress import serve

from storage import Store, Dictionaries

app = Flask(__name__)
assets = Environment(app)

home_dir = os.path.join(os.getcwd(), "storage.db")
db = Store(home_dir)
app.config["db"] = db

@app.route("/")
def index():
    file = open('rsc/form.json')
    data = json.load(file)
    return render_template("form.html", context=data)

@app.route("/send", methods=["POST"])
def send():
    json_str = json.dumps(request.json)
    data = Dictionaries(str(uuid.uuid4()), json_str)
    return jsonify({
        "success": True,
        "key": db.add(data)
    })

@app.route("/curriculum/<key>", methods=["GET"])
def curriculum(key: str):
    data = db.get(key)
    if not data:
        return render_template("error.html")

    return render_template("curriculum.html", context=json.dumps(data.__dict__))

assets.register('form-styles', Bundle('scss/form.scss', filters='pyscss', output='css/_form.css'))
assets.register('form-scripts', Bundle('js/validate.js', 'js/utils.js', 'js/form.js', filters='jsmin', output='js/_form.js'))

assets.register('curriculum-styles', Bundle('scss/curriculum.scss', filters='pyscss', output='css/_curriculum.css'))
assets.register('curriculum-scripts', Bundle('js/curriculum.js', filters='jsmin', output='css/_curriculum.js'))

if __name__ == "__main__":
    print("http://localhost:5000")
    serve(app, host="0.0.0.0", port=5000)

