from nltk.chat.util import Chat, reflections

pairs = [
            [
                r"what is your name?",
                ["My name is Jarvis and I will help you with your finacial queries today.",]
            ],
            [
                r"what are different investment options",
                ["Basically there are many options to invest\n1.Regional\n2.Stocks.\nIn which section would you like to invest?",]
            ],
            [
                r"(.*)Regional(.*)",
                ["There are many- SBI,HDFC,PNB. Which bank would you like to go for?",]
            ],
            [
                r"(.*)SBI(.*)",
                ["SBI offers 10 percent Interest.",]
            ],
            [
                r"(.*)HDFC(.*)",
                ["HDFC offers 09 percent Interest.",]
            ],
            [
                r"(.*)PNB(.*)",
                ["PNB offers 11 percent Interest.",]
            ],
            [
                r"maximum investment amount",
                ["No limit",]
            ],
            [
                r"(.*)Stocks(.*)",
                ["We have 2 companies to offer: 1. AAA 2. BBB.\n choose any one to know more.\n",]
            ],
            [
                r"AAA(.*)",
                ["The company AAA has a ROI = 10 percent",]
            ],
            [
                r"BBB(.*)",
                ["The company BBB has a ROI = 12 percent",]
            ],
            [
                r"hi|hey|hello(.*)",
                ["Hi nice to see you!",]
            ],
            [
                r"quit|bye",
                ["Goodbye ! It was nice to talk to you",]
            ],
            [
            	r"(.*)",
                ["Sorry didn't got it",]
            ],
        ]

def chatbot():
    '''Chat is the class that contains all the logic to be used by the chatbot,
    reflections is a predefined dictionary containing a set of input values and it's corresponding output values
    '''
    print("Booting up...\nHey I am a simple ChatBot made without ML, only using NLTK library.\n Please type in English language (lower case) what you want to ask me.\nPress Q to exit")
    chat = Chat(pairs, reflections)
    chat.converse()

if __name__ == "__main__":
    chatbot()
