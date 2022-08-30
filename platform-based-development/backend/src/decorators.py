import jwt
from functools import wraps
from flask import request, jsonify

from src.config import app
from src.models import UserModel\

def token_required(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        token = None

        if 'x-access-token' in request.headers:
            token = request.headers['x-access-token']

        if not token:
            return jsonify({'status': 'x-access-token is missing'}), 401

        try:
            data = jwt.decode(token, app.config['SECRET_KEY'])
            current_user = UserModel.query.filter_by(
                username=data['username']).first()
        except Exception:
            return jsonify({'status': 'x-access-token is invalid'}), 401

        return f(current_user, *args, **kwargs)

    return decorated