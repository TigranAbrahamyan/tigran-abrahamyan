import './Movie.css';

export const MovieComponent = ({ movie }) => {
  if (Object.keys(movie).length === 0) {
    return <h1 className="not-found">Movie not found</h1>;
  }

  return (
    <div className="movie">
      <h1>{movie.name}</h1>
      <p>{movie.description}</p>
      <img src={movie.img} alt={movie.name} />
    </div>
  );
}
