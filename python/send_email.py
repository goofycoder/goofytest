# Import smtplib for the actual sending function
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

server = smtplib.SMTP('smtp.gmail.com', 587)

#set up the proper connection for sending mail
server.ehlo()
server.starttls()

#log in to the server
username = 'username'
pswd = 'password' 
server.login(username, pswd)

#write mail
from_addr = 'username@gmail.com'
to_addr = 'to.her@gmail.com'

msg = MIMEMultipart()

msg['From'] = from_addr
msg['To'] = to_addr
msg['Subject'] = 'Email subject line'

body = 'Email body'
msg.attach(MIMEText(body, 'plain'))

html = """\
<html>
  <head></head>
  <body>
    <p>Hi!<br>
       Here is the <a href="http://www.python.org">link</a> you wanted.
    </p>
  </body>
</html>
"""
msg.attach(MIMEText(html, 'html'))

text = msg.as_string()

# send email
server.sendmail(from_addr, to_addr, text)

# enable debug info
server.set_debuglevel(True)

server.quit()
