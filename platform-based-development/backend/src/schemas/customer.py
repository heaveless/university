from .base.schema_base import SchemaBase

class CustomerSchema(SchemaBase):
    class Meta:
        fields = ('address', 'phone', 'email')