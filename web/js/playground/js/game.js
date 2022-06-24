const nickname = localStorage.getItem('nickname');

const startBtn = document.querySelector('#start');
const figure = document.querySelector('#figure');
const gamePlace = document.querySelector('.game-place');
const circles = document.querySelectorAll('.circles div');

const gamePlacePosition = gamePlace.getBoundingClientRect();
const difference = gamePlacePosition.right - gamePlacePosition.left;
const randomCircles = [];

let margin = 10;
let timerInterval;
let elementInterval;
let randomCircleInterval;
let circleRandomAppearInterval;

document.querySelector('#nickname').innerText = nickname;

document.querySelector('#logout').addEventListener('click', function() {
  localStorage.removeItem('nickname');
});

function elementSlideDown() {
  elementInterval = setInterval(function() {
    let circlePos = 0;
    const randomCircle = circles[Math.floor(Math.random() * circles.length)];

    if (!randomCircles[randomCircle]) {
      const randomPosition = Math.floor(Math.random() * difference);
      randomCircle.style.display = 'block';
      randomCircle.style.marginLeft = `${randomPosition}px`;
      randomCircles.push(randomCircle);
    }

    randomCircleInterval = setInterval(function() {
      circlePos += 10;
      randomCircle.style.marginTop = `${circlePos}px`;
      const randomCirclePosition = randomCircle.getBoundingClientRect();
      const figurePosition = figure.getBoundingClientRect();

      const randomCircleLeftDiff = Math.abs(randomCirclePosition.left - figurePosition.left);

      if (randomCircleLeftDiff <= figurePosition.width && randomCirclePosition.top >= figurePosition.top) {
        console.log('end', randomCircleLeftDiff);
        clearInterval(elementInterval);
      }

      if (randomCirclePosition.bottom >= gamePlacePosition.bottom) {
        randomCircle.style.marginTop = 0;
        randomCircle.style.display = 'none';
        randomCircles.pop(randomCircle);
        clearInterval(randomCircleInterval);
      }
    }, 10);

  }, 2000);
}

startBtn.addEventListener('click', function() {
  startBtn.innerText = 'Start';
  startBtn.disabled = true;
  figure.style.margin = 25;
  margin = 10;

  const time = document.querySelector('#time');
  let minutes = 0;
  let seconds = 0;
  let milliseconds = 0;

  timerInterval = setInterval(function() {
    milliseconds += 100;
    time.innerText = `${minutes < 10 ? '0' + minutes : minutes}:${seconds < 10 ? '0' + seconds : seconds}:${milliseconds}`;

    if (milliseconds >= 900) {
      seconds++;
      milliseconds = 0;
    }

    if (seconds >= 59) {
      minutes++;
      seconds = 0;
    }
  }, 100);
});

document.addEventListener('keydown', function(event) {
  if (startBtn.disabled === true) {
    const figurePosition = figure.getBoundingClientRect();

    if (event.key === 'ArrowLeft') {
      margin -= 10;
      figure.style.marginLeft = `${margin}px`;
    }

    if (event.key === 'ArrowRight') {
      margin += 10;
      figure.style.marginLeft = `${margin}px`;
    }

    if (figurePosition.right >= gamePlacePosition.right) {
      clearInterval(timerInterval);
      clearInterval(elementInterval);
      startBtn.innerText = 'Again';
      startBtn.disabled = false;
    }

    if (figurePosition.left <= gamePlacePosition.left) {
      clearInterval(timerInterval);
      clearInterval(elementInterval);
      startBtn.innerText = 'Again';
      startBtn.disabled = false;
    }
  }
});

elementSlideDown();
