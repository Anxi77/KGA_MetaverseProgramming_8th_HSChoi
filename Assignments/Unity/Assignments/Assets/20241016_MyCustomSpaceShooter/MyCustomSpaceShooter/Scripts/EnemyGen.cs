using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyGen : MonoBehaviour
{
    public GameObject Player;
    public GameObject Enemy;
    public float spawnInterval = 1f;
    private float nextSpawnTime;
    public GameObject[] spawnable;

    void Start()
    {
        nextSpawnTime = Time.time + spawnInterval;
        spawnable = GameObject.FindGameObjectsWithTag("EnemySpawnPos");

    }

    void Update()
    {
        int randompos = Random.Range(0, spawnable.Length);

        // ���� �ð��� �Ǿ���, ���� ������ ��ġ�� �ִ��� Ȯ��
        if (Time.time >= nextSpawnTime && spawnable.Length > 0)
        {
            // ������ Spawnable ��ġ ����
            GameObject randomSpawnable = spawnable[randompos];

            // ���õ� ��ġ�� Enemy ����
            Instantiate(Enemy, randomSpawnable.transform.position, Quaternion.identity);

            // ���� ���� �ð� ����
            nextSpawnTime = Time.time + spawnInterval;

            print($"���� �����Ǿ����ϴ�: {randomSpawnable.transform.position} ");

            print($"�����ʺ� ��ȣ : {randompos}");
        }
    }
}