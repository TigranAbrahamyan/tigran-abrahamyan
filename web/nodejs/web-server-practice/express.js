const express = require('express');
const app = express();
const port = 3000;

const users = [
  { id: 1, firstName: 'a', lastName: 'aa' },
  { id: 2, firstName: 'b', lastName: 'bb' },
  { id: 3, firstName: 'c', lastName: 'cc' },
];

app.get('/', (req, res) => {
  res.send('<h1>Home</h1>');
});

app.get('/users', (req, res) => {
  res.json(users);
});

app.get('/users/:id', (req, res) => {
  try {
    const findedUser = users.find((user) => user.id === +req.params.id);
    if (!findedUser) {
      throw new Error('User not found');
    }

    res.json(findedUser);
  } catch (err) {
    res.send(`<h1>${err.message}</h1>`);
  }
});

app.listen(port, () => console.log(`Server is running on http://localhost:${port}`));
