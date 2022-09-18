from flask import Flask, render_template, request
from flask_assets import Environment, Bundle
from waitress import serve

app = Flask(__name__)
assets = Environment(app)

@app.route("/")
def index():
    return render_template("form.html")

@app.route("/curriculum", methods=["POST"])
def curriculum():
    context = request.form.to_dict()
    return render_template("curriculum.html", context=context)

assets.register('form-styles', Bundle('scss/form.scss', filters='pyscss', output='css/form.css'))

assets.register('curriculum-styles', Bundle('scss/curriculum.scss', filters='pyscss', output='css/curriculum.css'))

if __name__ == "__main__":
    serve(app, host="0.0.0.0", port=5000)

