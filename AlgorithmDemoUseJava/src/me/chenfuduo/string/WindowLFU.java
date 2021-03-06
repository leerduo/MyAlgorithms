package me.chenfuduo.string;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;


public class WindowLFU<K,V> {
	
	private int mCapacity;
	private int mWindowSize;
	private int total;
	private int shoot;
	
	private Queue<K> mWindow;
	private Map<K,CacheNode<V>> mCache;
	
	
	class CacheNode<V>{
		public V value;
		public int count;
		public CacheNode(V value, int count) {
			this.value = value;
			this.count = count;
		}
		
	}


	public WindowLFU(int mCapacity, int mWindowSize) {
		this.mCapacity = mCapacity;
		this.mWindowSize = mWindowSize;
		shoot = 0;
		total = 0;
		mWindow = new LinkedList<>();
		mCache = new LinkedHashMap<>();
	}
	
	
	public V get(K key){
		total++;
		V value = null;
		if (mCache.containsKey(key)) {
			shoot++;
			value = mCache.get(key).value;
			this.put(key, value);
		}
		return value;
	}
	
	public void put(K key,V value){
		//向队尾插入元素
		mWindow.offer(key);
		if (mWindow.size() > mWindowSize) {
			//移除队首元素
			K first = mWindow.poll();
			if (mCache.containsKey(first)) {
				WindowLFU<K, V>.CacheNode<V> item = mCache.get(first);
				item.count--;
				if (item.count == 0) {
					mCache.remove(first);
				}
			}
		}
		if (mCache.containsKey(key)) {
			mCache.remove(key);
		}
		int count = 0;
		for (K k : mWindow) {
			if (k.equals(key)) {
				count++;
			}
		}
		
		//Make sure insert front
		Map<K, CacheNode<V>> newCache = new LinkedHashMap<>();
		newCache.put(key, new CacheNode<>(value, count));
		newCache.putAll(mCache);
		mCache = newCache;
		updateCache();
		
	}

	public void remove(K key){
		mCache.remove(key);
		updateCache();
	}
	
	
	private void updateCache() {
		List<Map.Entry<K, CacheNode<V>>> tempList = new ArrayList<>(mCache.entrySet());
		Collections.sort(tempList,new Comparator<Map.Entry<K, CacheNode<V>>>() {

			@Override
			public int compare(Map.Entry<K, WindowLFU<K, V>.CacheNode<V>> t1,
					Map.Entry<K, WindowLFU<K, V>.CacheNode<V>> t2) {
				return t2.getValue().count - t1.getValue().count;
			}
		});
		if (tempList.size() > mCapacity) {
			tempList = tempList.subList(0, mCapacity);
		}
		mCache.clear();
		for (Map.Entry<K, CacheNode<V>> entry : tempList) {
			mCache.put(entry.getKey(), entry.getValue());
		}
	}
	
	public float hitrate() {
        if (total == 0) {
            return 0;
        }
        return (float) shoot / total;
    }


    // for test, ignore
    public Map<K, CacheNode<V>> getCache(){
        return mCache;
    }

    public Queue<K> getWindow(){
        return mWindow;
    }
	
	
}
