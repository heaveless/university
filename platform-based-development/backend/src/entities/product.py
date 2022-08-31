from sqlalchemy import Column, String

from .base.entity_base import EntityBase
from ..models.supplier import Supplier

class ProductModel(EntityBase):
    __tablename__ = 'products'

    name = Column(String, unique=False)
    suppler = Column(Supplier, unique=False)

    def __init__(self, name, suppler):
        self.name = name
        self.suppler = suppler

    def __repr__(self):
        return " - repr - "
        