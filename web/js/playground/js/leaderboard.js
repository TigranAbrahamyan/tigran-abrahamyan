document.querySelector('#nickname').innerText = localStorage.getItem('nickname');

document.querySelector('#logout').addEventListener('click', function() {
  localStorage.removeItem('nickname');
});

const leaders = JSON.parse(localStorage.getItem('leaders')) || [];

document.querySelector('.table tbody').insertAdjacentHTML(
  'afterbegin',
  leaders
    .sort((a, b) => b.time.localeCompare(a.time))
    .map((n, i) => (`
      <tr>
        <th>${i + 1}</th>
        <td>${n.time}</td>
        <td>${n.nickname}</td>
      </tr>
    `)).join(''),
);
