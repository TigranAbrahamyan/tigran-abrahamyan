class Database {
  static instance = null;

  static get() {
    if (!localStorage.getItem('db')) {
      localStorage.setItem('db', JSON.stringify([]));
    }

    if (!Database.instance) {
      Database.instance = new Database();
    }

    return Database.instance;
  }

  static save(table) {
    const db = JSON.parse(localStorage.getItem('db')) || [];
    const saveTable = db.map((n) => (n.name === table.name && { ...n, values: table.values }));
    localStorage.setItem('db', JSON.stringify(saveTable));
  }

  getTable(name) {
    const db = JSON.parse(localStorage.getItem('db')) || [];
    const findedTable = db.find((n) => n.name === name);

    return new Table(findedTable.name, findedTable.columns, findedTable.values);
  }

  createTable(name, columns, values = []) {
    const db = JSON.parse(localStorage.getItem('db')) || [];
    if (!db.find((n) => n.name === name)) {
      const newTable = new Table(name, columns, values);
      db.push(newTable);
      localStorage.setItem('db', JSON.stringify(db));

      return newTable;
    }
  }
}

class Table {
  constructor(name, columns, values) {
    this.name = name;
    this.columns = columns;
    this.values = values;
  }

  #isRowValid(row) {
    return Array.isArray(row) && row.length === this.columns.length - 1;
  }

  add(row) {
    if (!this.#isRowValid(row)) {
      return;
    }

    const incrementedID = (this.values[this.values.length - 1] || [])[0] + 1 || 1;
    this.values.push([ incrementedID, ...row ]);
    Database.save(this);
  }

  update(id, row) {
    if (!this.#isRowValid(row)) {
      return;
    }

    this.values = this.values.map((n) => {
      if (n[0] === id) {
        return [ id, ...row ];
      }

      return n;
    });

    Database.save(this);
  }

  delete(id) {
    this.values = this.values.filter((n) => n[0] !== id);
    Database.save(this);
  }

  get(id) {
    return this.values.find((n) => n[0] === id);
  }
}
