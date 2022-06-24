document.querySelector('#login').addEventListener('click', function() {
  const inputValue = document.querySelector('#nickname').value;
  localStorage.setItem('nickname', inputValue);
});
