import './Movie.css';

export const MovieComponent = ({ movie }) => {
  return (
    <div className="movie">
      <h1>{movie.name}</h1>
      <p>{movie.description}</p>
      <img src={movie.img} alt={movie.name} />
    </div>
  );
}
