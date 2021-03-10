# Importing Libraries
import pandas as pd

# Importing Dataset
data_set = pd.read_csv('diabetes.csv')
X = data_set.iloc[:, :-1]   # Independent Variables separated as X
y = data_set.iloc[:,-1]    # Dependent Variables into y

# 1. Splitting X,y into Train & Test
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.20, random_state=0)


# 2. Scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# Machine: Classifier | NB: Gaussian Naive Bayes
from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X_train, y_train)

# Predictions
y_pred = classifier.predict(X_test)

# Validating Predictions using Confusion Matrix
from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.metrics import accuracy_score
a=accuracy_score(y_test,y_pred)
print("Accuracy = ",a)