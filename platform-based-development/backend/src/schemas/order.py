from .base.schema_base import SchemaBase

class OrderSchema(SchemaBase):
    class Meta:
        fields = ('number', 'ordered', 'shipped', 'ship_to', 'status', 'total')