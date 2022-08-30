class CustomerModel:
    __tablename__ = 'customers'

    address = Column(String)
    phone = Column(String)
    email = Column(String)
