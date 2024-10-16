using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class CollisionMessageTest : MonoBehaviour
{
    #region �������� �浹 �Ǵ� ��ȣ�ۿ뿡 ���ؼ� ȣ��Ǵ� �޼��� �׽�Ʈ
    /* OnCollsionXX �޼��� ȣ�� ���� : ȣ�� �� ������Ʈ�� Collider ������Ʈ�� �����ؾ� �ϸ�,
     * �浹 �޽��� �Լ��� ȣ���ϴ� ��ü�� Rigidbody �̹Ƿ� , �浹�� �� ������Ʈ �� �ѿ��� �� Rigidbody�� �پ� �־�� ȣ��ȴ�.
     */
    //1. OnCollisionEnter : �������� �浹�� �Ͼ���� ȣ�� *Collsion Ŭ���� : �浹 ��ü�� ����(��ġ �ӵ� ���)�� ����ִ� Ŭ�����̴�.
    private void OnCollisionEnter(Collision collision)
    {
        Collider otherCollider = collision.collider; //�浹�� ����Ų ���

        print($"�浹�� �Ͼ. ȣ�� ��ü {name}, �浹 ��� : {otherCollider.name}");
    }

    //2. OnCollisionExit : �浹 �Ǿ��� Collider�� �ٽ� �浹���°� �ƴϰ� �Ǹ� ȣ��.
    private void OnCollisionExit(Collision coll)
    {
        print($"�浹�ߴٰ� ������. ȣ�� ��ü {name}, �浹 ��� : {coll.collider.name}");
    }

    //3. OnCollsionStay : �浹���϶� �����Ӹ��� ȣ��.
    private void OnCollisionStay(Collision c)
    {
        print($"�浹�ϴ���. ȣ�� ��ü {name}, �浹 ��� : {c.collider.name}");
    }
    #endregion
}
