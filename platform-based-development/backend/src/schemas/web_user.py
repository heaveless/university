from .base.schema_base import SchemaBase

class WebUserSchema(SchemaBase):
    class Meta:
        fields = ('username', 'password', 'state')