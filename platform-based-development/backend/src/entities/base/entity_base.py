from sqlalchemy import Column, String, DateTime

class EntityBase:
    id = Column(String, primary_key=True)
    created_at = Column(DateTime, unique=True)
    updated_at = Column(DateTime, unique=True)
    deleted_at = Column(DateTime, unique=True)
