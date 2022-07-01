import { Button } from '../../../lib/elements/Button/Button';
import { InputField } from '../../../lib/elements/Field/InputField';
import { Modal } from '../../../lib/elements/Modal/Modal';

export const MovieModal = ({
  name,
  setName,
  description,
  setDescription,

  modalVisibility,
  handleModalVisibility,
  addMovie,
}) => {
  return (
    <Modal visibility={modalVisibility} onClose={() => handleModalVisibility(false)} title="Add film">
      <InputField
        name="name"
        placeholder="Name"
        value={name}
        onChange={(e) => setName(e.target.value)}
      />
      <InputField
        name="description"
        placeholder="Description"
        value={description}
        onChange={(e) => setDescription(e.target.value)}
      />
      <Button onClick={addMovie}>Add</Button>
    </Modal>
  );
}
