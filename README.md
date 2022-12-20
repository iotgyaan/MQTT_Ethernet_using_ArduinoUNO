# MQTT_Ethernet_using_ArduinoUNO

Publish and Subscribe with MQTT Ethernet using Arduino UNO board.


-------> Install Nodejs and Node-red <--------

STEP 1

1. Install Node.js


STEP 2

Node-RED

Windows CMD:

node --version && npm --version

npm install -g --unsafe-perm node-red

node-red


-----------> Install Nodes <------------

STEP 1 

1. Download flows.json file and import to node-red

STEP 2

1. inject: Injects a message into a flow either manually or at regular intervals. The message payload can be a variety of types, including strings, JavaScript objects or the current time.

2. debug: Displays selected message properties in the debug sidebar tab and optionally the runtime log. By default it displays msg.payload, but can be configured to display any property, the full message or the result of a JSONata expression.

3. mqtt in: Connects to a MQTT broker and subscribes to messages from the specified topic.

4. mqtt out: Connects to a MQTT broker and publishes messages.
