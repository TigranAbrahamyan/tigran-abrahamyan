import React from 'react';
import './Modal.css';

export const Modal = ({ visibility, onClose, title, children }) => {
  React.useEffect(() => {
    if (visibility) {
      document.body.style.overflow = 'hidden';
    } else {
      document.body.style.overflow = 'auto';
    }
  }, [visibility]);

  if (!visibility) {
    return null;
  }

  return (
    <div className="modal">
      <div className="modal__box">
        <div className="modal__header">
          <h1>{title}</h1>
          <span className="close" onClick={onClose}>&times;</span>
        </div>
        <div className="modal__content">{children}</div>
      </div>
    </div>
  );
}
