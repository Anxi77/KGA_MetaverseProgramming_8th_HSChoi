using UnityEngine;

public class BulletMove : MonoBehaviour
{
    public float velocity = 10f;
    public float lifeTime = 2f;

    private Vector3 direction;

    public void Start()
    {
        // �Ѿ��� ������ �����մϴ�.
        direction = transform.rotation * Vector3.up;

        // �Ѿ��� ȸ���� ���⿡ �°� �����մϴ�.
        float angle = Mathf.Atan2(direction.y, direction.x) * Mathf.Rad2Deg;
        transform.rotation = Quaternion.AngleAxis(angle - 90, Vector3.forward);

        // �Ѿ��� ������ �����մϴ�.
        Destroy(gameObject, lifeTime);
    }

    private void Update()
    {
        // ������ �������� �Ѿ��� �̵���ŵ�ϴ�.
        transform.Translate(direction * velocity * Time.deltaTime, Space.World);
    }

    private void OnCollisionEnter(Collision collision)
    {
        DestroyImmediate(gameObject);
    }
}