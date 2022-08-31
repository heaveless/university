from sqlalchemy import Column, Integer, DateTime

from .base.entity_base import EntityBase
from ..models.address import Address
from ..enums.order_status import OrderStatus 

class OrderModel(EntityBase):
    __tablename__ = 'orders'

    number = Column(Integer, unique=False)
    ordered = Column(DateTime, unique=False)
    shipped = Column(DateTime, unique=False)
    ship_to = Column(Address, unique=False)
    status = Column(OrderStatus, unique=False)
    total = Column(Integer, unique=False) # Real

    def __init__(self, number, ordered, shipped, ship_to, status, total):
        self.number = number
        self.ordered = ordered
        self.shipped = shipped
        self.ship_to = ship_to
        self.status = status
        self.total = total

    def __repr__(self):
        return " - repr - "
