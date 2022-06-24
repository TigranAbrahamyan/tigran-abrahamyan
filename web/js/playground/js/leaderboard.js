document.querySelector('#nickname').innerText = localStorage.getItem('nickname');

document.querySelector('#logout').addEventListener('click', function() {
  localStorage.removeItem('nickname');
});
