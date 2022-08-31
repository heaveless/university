from sqlalchemy import Column, String

from .base.entity_base import EntityBase
from ..enums.user_state import UserState 

class WebUserModel(EntityBase):
    __tablename__ = 'web_users'

    username = Column(String, unique=False)
    password = Column(String, unique=False)
    state = Column(UserState, unique=False)

    def __init__(self, username, password, state):
        self.username = username
        self.password = password
        self.password = password
        self.state = state

    def __repr__(self):
        return " - repr - "
