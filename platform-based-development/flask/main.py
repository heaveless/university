from flask import Flask, render_template, request
from flask_assets import Environment, Bundle
from waitress import serve

app = Flask(__name__)
assets = Environment(app)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/hello", methods=["POST"])
def hello():
    name = request.form.get("name")
    return render_template("curriculum.html", context={
        'name': name    
    })

assets.register('theme', Bundle('scss/theme.scss', filters='pyscss', output='css/theme.css'))

if __name__ == "__main__":
    serve(app, host="0.0.0.0", port=5000)

