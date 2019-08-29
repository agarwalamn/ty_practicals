# -*- coding: utf-8 -*-
"""
Created on Wed Aug 28 11:14:34 2019

@author: cglab
"""

import pandas as pd
import numpy as np
from pprint import pprint
dataset = pd.read_csv('./data/zoo.csv',
                      names=['animal_name','hair',
                      'feathers','eggs','milk',
                      'airbone','aquatic','predator',
                      'toothed','backbone','breathes',
                      'venomous','fins','legs','tail',
                      'domestic','catsize','class',])
dataset=dataset.drop('animal_name',axis=1)

###########################################

def entropy(col):
    elements,counts = np.unique(col,return_counts=True)
    t_count=np.sum(counts)
    entrop = np.sum([(-counts[i]/t_count)*np.log2(counts[i]/t_count) for i in range(len(elements))])
    return entrop
    
##########################################
    
def InfoGain(data,split_attr, target_name="class"):
    total_entropy = entropy(data[target_name])
    vals,counts = np.unique(data[split_attr],return_count=True)
    w_entropy = np.sum([(counts[i]/np.sum(counts))*entropy(data.where(data[split_attr]==vals[i]).dropna()[target_name]) for i in range(len(vals))])
    info_gain = total_entropy - w_entropy
    return info_gain
    
##########################################

def ID3(data,originaldata,features,target_attribute="class",parent_node = None):
    if(len(np.unique(data[target_attribute]))<=1):
        return np.unique(data[target_attribute])[0]
    elif(len(data)==0):
        return np.unique(originaldata[target_attribute])[np.argmax(np.unique(originaldata[target_attribute],return_counts=True)[1])]
    elif(len(features == 0)):
        return parent_node
    else:
        parent_node_class = np.unique(data[target_attribute])[np.argmax(np.unique(data[target_attribute],return_counts=True)[1])]
    item_values = [InfoGain(data,feature,target_attribute) for feature in features] 
    best_feature_index = np.argmax(item_values)
    best_feature = features[best_feature_index]
    tree = {best_feature:{}}
    features = [i for i in features if i != best_feature]
    for value in np.unique(data[best_feature]):
        value = value
        sub_data = data.where(data[best_feature] == value).dropna()
        subtree = ID3(sub_data,dataset,features,target_attribute,parent_node_class)
        tree[best_feature][value] = subtree
    return tree

###########################################

def predict(query,tree,default = 1 ):
    for key in list(query.keys()):
        if key in list(tree.keys()):
            try:
                result = tree[key][query[key]] 
            except:
                return default
            result = tree[key][query[key]]
            if isinstance(result,dict):
                return predict(query,result)
            else:
                return result

def train_test_split(dataset):
    training_data = dataset.iloc[:80].reset_index(drop=True)
    testing_data = dataset.iloc[80:].reset_index(drop=True)
    return training_data,testing_data
training_data = train_test_split(dataset)[0]
testing_data = train_test_split(dataset)[1] 
def test(data,tree):
    queries = data.iloc[:,:-1].to_dict(orient = "record")
    predicted = pd.DataFrame(columns=["predicted"])
    for i in range(len(data)):
        predicted.loc[i,"predicted"] = predict(queries[i],tree,1.0) 
    print('The prediction accuracy is: ',(np.sum(predicted["predicted"] == data["class"])/len(data))*100,'%')
tree = ID3(training_data,training_data,training_data.columns[:-1])
pprint(tree)
test(testing_data,tree)