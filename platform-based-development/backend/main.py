from flask import Flask
from flask_cors import CORS
from flask_migrate import Migrate
from waitress import serve

from src.app import app, db
from src.config import logging

migrate = Migrate(app, db)
cors = CORS(app)

if __name__ == '__main__':
    logging.info("Starting server...")
    serve(app, host="0.0.0.0", port=5000)