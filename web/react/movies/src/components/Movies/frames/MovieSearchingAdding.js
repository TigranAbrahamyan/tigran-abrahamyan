import { Button } from '../../../lib/elements/Button/Button';
import { InputField } from '../../../lib/elements/Field/InputField';

export const MovieSearchingAdding = ({ searchValue, setSearchValue, handleModalVisibility }) => {
  return (
    <div className="movies__searching-adding">
      <InputField
        name="search"
        placeholder="Search"
        value={searchValue}
        onChange={(e) => setSearchValue(e.target.value)}
      />
      <Button onClick={() => handleModalVisibility(true)} styles={{ width: '200px' }}>Add</Button>
    </div>
  )
}
