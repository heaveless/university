from .base.schema_base import SchemaBase

class AccountSchema(SchemaBase):
    class Meta:
        fields = ('billing_address', 'is_closed', 'open', 'closed')