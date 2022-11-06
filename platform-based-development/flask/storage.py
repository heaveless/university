import sqlite3 as dbapi2

class Dictionaries:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class Store:
    def __init__(self, dbfile):
        self.dbfile = dbfile

    def add(self, data):
        with dbapi2.connect(self.dbfile) as connection:
            cursor = connection.cursor()
            query = "INSERT INTO DICTIONARIES (key, value) VALUES (?, ?)"
            cursor.execute(query, (data.key, data.value))
            connection.commit()
        return data.key

    def get(self, key):
        with dbapi2.connect(self.dbfile) as connection:
            cursor = connection.cursor()
            query = "SELECT value FROM DICTIONARIES WHERE (key = ?)"
            cursor.execute(query, (key,))
            value = cursor.fetchone()
        data = Dictionaries(key, value=value)
        return data