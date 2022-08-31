from sqlalchemy import Column, Boolean, DateTime

from .base.entity_base import EntityBase
from ..models.address import Address 

class AccountModel(EntityBase):
    __tablename__ = 'accounts'

    billing_address = Column(Address, unique=False)
    is_closed = Column(Boolean, unique=False)
    open = Column(DateTime, unique=False)
    closed =  Column(DateTime, unique=False)

    def __init__(self, billing_address, is_closed, open, closed):
        self.billing_address = billing_address
        self.is_closed = is_closed
        self.open = open
        self.closed = closed

    def __repr__(self):
        return " - repr - "