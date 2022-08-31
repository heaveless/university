from .base.schema_base import SchemaBase

class ProductSchema(SchemaBase):
    class Meta:
        fields = ('name', 'suppler')