import React from 'react';
import io from 'socket.io-client';

const socket = io('http://localhost:3001');

function App() {
  const [ message, setMessage ] = React.useState('');
  const [ messages, setMessages ] = React.useState([]);

  React.useEffect(() => {
    getMessages();
  }, [message]);

  const sendMessage = async () => {
    socket.emit('send-message', message);
    setMessages([ message, ...messages ]);
    setMessage('');
  };

  const getMessages = () => {
    socket.on('send-broadcast-message', (msg) => {
      setMessages([ msg, ...messages ]);
      setMessage('');
    });
  };

  return (
    <div>
      <input placeholder="Message" value={message} onChange={(e) => setMessage(e.target.value)} />
      <button onClick={sendMessage}>Send message</button>
      <ul>
        {messages.map((message, index) => (
          <li key={index}>{message}</li>
        ))}
      </ul>
    </div>
  );
}

export default App;
