const output = document.querySelector('#output');
const firstInput = document.querySelector('#first-input');
const secondInput = document.querySelector('#second-input');
const operator = document.querySelector('#operator');
const reset = document.querySelector('#reset');
const buttons = document.querySelectorAll('.buttons button');

const setInitialState = () => {
  output.innerText = 0;
  firstInput.value = '';
  secondInput.value = '';
  operator.innerText = '+';
};

setInitialState();

[firstInput, secondInput].forEach((input) => {
  input.addEventListener('input', () => {
    input.value = input.value.replace(/\D/g, '');
  });
});

buttons.forEach((button) => {
  button.addEventListener('click', ({ target }) => {
    if (firstInput.value && secondInput.value) {
      operator.innerText = target.innerText;
      let result;

      switch (operator.innerText) {
        case '+':
          result = Number(firstInput.value) + Number(secondInput.value);
          break;
        case '-':
          result = Number(firstInput.value) - Number(secondInput.value);
          break;
        case '*':
          result = Number(firstInput.value) * Number(secondInput.value);
          break;
        case '/':
          result = Number(firstInput.value) / Number(secondInput.value);
          break;
        default:
          result = 0;
      }

      output.innerText = result;
    }
  });
});

reset.addEventListener('click', () => {
  setInitialState();
});

document.addEventListener('keydown', (event) => {
  if (event.key === 'Escape') {
    setInitialState();
  }
});
