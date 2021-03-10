#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Dec 16 10:20:36 2020

@author: prem
"""

import pandas as pd
import matplotlib.pyplot as plt

dataset = pd.read_csv('iris.csv')

dataset.head()

print(dataset.shape[1]-1)

print(dataset.dtypes)

dataset.describe()

dataset.hist()
plt.show()

dataset[['sepal-length', 'sepal-width', 'petal-length', 'petal-width']].plot.hist(bins = 10, title='All features')
plt.show()


dataset[['sepal-length']].plot.hist(bins = 10, title='sepal-length')
plt.show()

dataset[['sepal-width']].plot.hist(bins = 10, title='sepal-width')
plt.show()

dataset[['petal-length']].plot.hist(bins = 10, title='petal-length')
plt.show()

dataset[['petal-width']].plot.hist(bins = 10, title='petal-width')
plt.show()

dataset.plot.box(title = "All features")
plt.show()

dataset[['sepal-length']].plot.box(title = 'sepal-length')
plt.show()

dataset[['sepal-width']].plot.box(title = 'sepal-width')
plt.show()

dataset[['petal-length']].plot.box(title = 'petal-length')
plt.show()

dataset[['petal-width']].plot.box(title = 'petal-width')
plt.show()