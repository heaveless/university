class WebUserModel:
    __tablename__ = 'web_users'

    username = Column(String)
    password = Column(String)
    state = UserStateModel
