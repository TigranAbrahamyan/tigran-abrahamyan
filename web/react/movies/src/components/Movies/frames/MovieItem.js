import { Button } from '../../../lib/elements/Button/Button';

export const MovieItem = ({ name, description, img, deleteMovie }) => {
  return (
    <div>
      <img src={img} alt={name} />
      <div className="movies__items__content">
        <h1>{name}</h1>
        <p>{description}</p>
        <Button onClick={deleteMovie}>Delete</Button>
      </div>
    </div>
  );
}
