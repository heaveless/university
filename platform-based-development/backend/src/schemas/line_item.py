from .base.schema_base import SchemaBase

class LineItemSchema(SchemaBase):
    class Meta:
        fields = ('quantity', 'price')