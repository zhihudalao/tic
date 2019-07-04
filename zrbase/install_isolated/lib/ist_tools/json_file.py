#!/usr/bin/env python
#-*- coding: utf-8 -*-  
import json

#写操作：单行+分隔符（覆盖）
def json_write(data , file_name):
  with open(file_name+".json","w") as outfile:
    json.dump(data,outfile,ensure_ascii=False,encoding='utf-8')
    outfile.write('\n')
  print("write successfully...")

#写操作：单行+分隔符（追加）
def json_append(data , file_name):
  with open(file_name+".json","a") as outfile:
    json.dump(data,outfile,ensure_ascii=False,encoding='utf-8')
    outfile.write('\n')
  print("write successfully...")

#读操作：单行，没有分隔符
def json_read(data , file_name):
  with open(file_name+".json",'r') as loadfile:
    data = json.load(loadfile)
  print json.dumps(data,ensure_ascii=False,encoding='utf-8')

#读操作：单行，有分隔符
def json_load(data , file_name):
  loadfile=open(file_name+".json","r")
  for line in loadfile:
    data=json.loads(line)
    print json.dumps(data,ensure_ascii=False,encoding='utf-8')
  loadfile.close()

#读操作：多行，有分隔符
def json_read_lines(data , file_name):
  loadfile=open(file_name+".json","r")
  data=list()
  for line in loadfile:
    data.append(json.loads(line))
  #print json.dumps(data,ensure_ascii=False,encoding='utf-8')
  loadfile.close()
  return data

#文件清空
def json_clear(file_name):
  loadfile=open(file_name+".json","w+")
  loadfile.truncate()#清空文件内容

