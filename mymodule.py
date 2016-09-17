import json
class Module:
    def __init__(self):
        readChannel = ""
        writeChannel = ""

    def getReadChannels(self):
        return self.readChannel

    def getWriteChannels(self):
        return self.writeChannel

    def cycle(self):
        return

class MyModule(Module):
    def __init__(self):
        Module.__init__(self)
        self.readChannel = "MY_READ_CHANNEL"
        self.writeChannel = "MY_WRITE_CHANNEL"

    def cycle(self):
        print("I am your python cycle")
        print("The data I have is %s"%(self.MY_READ_CHANNEL))
        return
