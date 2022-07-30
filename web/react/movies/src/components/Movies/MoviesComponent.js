import { MovieModal } from './frames/MovieModal';
import { MovieItems } from './frames/MovieItems';
import { MovieSearchingAdding } from './frames/MovieSearchingAdding';

import './Movies.css';

export const MoviesComponent = ({
  searchValue,
  setSearchValue,
  name,
  setName,
  description,
  setDescription,

  movies,
  moviesCount,
  modalVisibility,
  addMovie,
  deleteMovie,
  handleModalVisibility,
}) => {
  return (
    <div className="movies">
      <MovieSearchingAdding
        searchValue={searchValue}
        setSearchValue={setSearchValue}
        handleModalVisibility={handleModalVisibility}
        moviesCount={moviesCount}
      />

      <MovieItems
        movies={movies}
        deleteMovie={deleteMovie}
      />

      <MovieModal
        name={name}
        setName={setName}
        description={description}
        setDescription={setDescription}

        modalVisibility={modalVisibility}
        handleModalVisibility={handleModalVisibility}
        addMovie={addMovie}
      />
    </div>
  );
}
