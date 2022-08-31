from enum import unique
from sqlalchemy import Column, Integer

from .base.entity_base import EntityBase

class LineItemModel(EntityBase):
    __tablename__ = 'line_items'

    quantity = Column(Integer, unique=False)
    price = Column(Integer, unique=False)

    def __init__(self, quantity, price):
        self.quantity = quantity
        self.price = price

    def __repr__(self):
        return " - repr - "
        