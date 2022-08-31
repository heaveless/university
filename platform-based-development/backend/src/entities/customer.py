from enum import unique
from sqlalchemy import Column

from .base.entity_base import EntityBase
from ..models.address import Address 
from ..models.email import Email 
from ..models.phone import Phone 

class CustomerModel(EntityBase):
    __tablename__ = 'customers'

    address = Column(Address, unique=False)
    phone = Column(Phone, unique=False)
    email = Column(Email, unique=False)

    def __init__(self, address, phone, email):
        self.address = address
        self.phone = phone
        self.email = email

    def __repr__(self):
        return " - repr - "
        