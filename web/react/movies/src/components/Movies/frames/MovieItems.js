import { MovieItem } from './MovieItem';

export const MovieItems = ({ movies, deleteMovie }) => {
  return (
    <div className="movies__items">
      {movies.map((movie) => (
        <MovieItem key={movie.id} deleteMovie={() => deleteMovie(movie.id)} {...movie} />
      ))}
    </div>
  );
}