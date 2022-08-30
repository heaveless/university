
class UserStateModel:
    __tablename__ = 'user_states'


    new = Column(Boolean)
    active = Column(Boolean)
    blocked = Column(Boolean)
    banned = Column(Boolean)

