import './InputField.css';

export const InputField = ({ type = 'text', label, value, name, placeholder, onChange}) => {
  return (
    <div className="input-field">
      {label && <label htmlFor="input-field">{label}</label>}
      <input
        type={type}
        value={value}
        name={name}
        placeholder={placeholder}
        onChange={onChange}
        id="input-field"
      />
    </div>
  );
};
