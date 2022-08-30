class AccountModel:
    __tablename__ = 'accounts'

    billing_address = Column(String)
    is_closed = Column(Boolean)
    open = Column(Date)
    closed =  Column(Date)

