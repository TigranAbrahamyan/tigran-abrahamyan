const db = Database.get();
db.createTable('users', ['id', 'username', 'password']);

db.getTable('users').add(['valod', 'asd']);
db.getTable('users').add(['vlad', 'zxc']);
db.getTable('users').add(['john', 'dom']);
db.getTable('users').add(['johnson', 'bom']);

db.getTable('users').add(['error']);

console.log(db.getTable('users').get(2));
db.getTable('users').delete(1);

db.getTable('users').update(3, ['vladik', 'qwe']);
db.getTable('users').update(1, ['vladan', 'ghbtn']);

db.getTable('users').update(2, 'error');
