<h1>Minitalk</h1>
<p>The purpose of this project is to code a small data exchange program
using UNIX signals.</p>

<h2>Foreword</h2>
<p>You must create a communication program in the form of a client and a server.<br><br>
<p>The server must be started first. After its launch, it has to print its PID.<br>
<tr>
  The client takes two parameters:<br>
    <li>The server PID.</li>
    <li>The string to send.</li>
</tr>
  <br>
<p>The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
<p>The server has to display the string pretty quickly. Quickly means that if you think
it takes too long, then it is probably too long.</p>
<p>Your server should be able to receive strings from several clients in a row without
needing to restart.</p>

<p>The communication between your client and your server has to be done only using
UNIX signals.</p>

<p>You can only use these two signals: SIGUSR1 and SIGUSR2</p>

<img src="https://i.ibb.co/Kjwqk2M/Screenshot-2023-12-11-at-20-48-23.png">
<img src="https://i.ibb.co/3TL7xZS/Screenshot-2023-12-11-at-20-49-07.png">

<h1>Bonus Part</h1>

<p>The server acknowledges every message received by sending back a signal to the
client.</p>

<p>Unicode characters support!</p>
