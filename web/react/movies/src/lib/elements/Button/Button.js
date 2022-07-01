import './Button.css';

export const Button = ({ onClick, styles, children }) => {
  return (
    <button onClick={onClick} style={styles}>{children}</button>
  );
}
