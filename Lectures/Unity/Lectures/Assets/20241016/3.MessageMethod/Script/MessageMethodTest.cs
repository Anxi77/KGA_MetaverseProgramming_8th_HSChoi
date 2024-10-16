using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MessageMethodTest : MonoBehaviour
{
    #region Message Function(Event Function)
    /*�޽��� �Լ�(�̺�Ʈ �Լ�) : �����ڰ� ���� ȣ������ �ʾƵ� ����Ƽ ���� ���μ����� �߻��ϴ� �̺�Ʈ�� ���� ����Ƽ ������ ȣ�����ִ� �Լ�.
      �Լ� �̸��� �Ķ���Ͱ� ������ ������, �Լ� �������� ȣ�� ������ �ٸ���.
     */

    /*0. Awake : ��ü�� �ε���ڸ��� ȣ��ȴ�.
      ���� : �ش� GameObject ���� �ٸ� ������Ʈ�� ���� ���������� , 
            �ٸ� GameObject�� ���� �ε尡 �ȵǾ ������ �Ұ����� ���ɼ��� ���� 
            �׷��Ƿ� �ش� ������Ʈ�� ������ ���� ������Ʈ�� �ʱ�ȭ �� �뵵�� ���
     */
    private BoxCollider boxCollider;

    private void Awake()
    {
        boxCollider = GetComponent<BoxCollider>();

        if(transform.position.y > 1) 
        {
            boxCollider.center = new Vector3(0, -1, 0);
        }
    }

    //1. Start : ������ �ε� �� ��, ���� ù ������ ���� ������ ȣ��ȴ�.
    private string state = "Not Ready";
    private bool isInit = false;

    private void Start()
    {
        print("Start �޽��� �Լ� ȣ��.");
        state = "Ready";
        isInit = true;
    }


    //2. Update : ������ �ε� �� ��, �� �����Ӹ��� �ѹ��� ȣ��.
    public int frameCount = 0;
    private void Update()
    {
        //print($"Update �޽��� �Լ� ȣ�� . {framecount++}");
    }
    
    /*3. OnEnable/OnDisable : �ش� ��ü �Ǵ� ������Ʈ�� Ȱ��ȭ �ǰų� ��Ȱ��ȭ �Ǹ� ȣ��. 
    ���� : OnEnable()�� ��ü �ε尡 �Ϸ�� �Ŀ� ��� ȣ��ǹǷ�, ó�� 1ȸ�� Start �Լ����� ���� ȣ��ȴ�.
    �̰���� �� : �� ������Ʈ�� �ʱ�ȭ ���� ���θ� üũ���ָ� ����.
     */
    private void OnEnable()
    {
        if (false == isInit) return;
        print("OnEnable �Լ� ȣ��.");
        print($"���� ��ü ���� {state}");
    }
    private void OnDisable()
    {
        print("OnDisable �Լ� ȣ��.");
    }

    /*4. OnDestroy : ���� ������Ʈ �Ǵ� ������Ʈ�� �ı��ɶ� ȣ��.
     ���� : ȣ��Ǳ� �� OnDisable()�� ���� ȣ��ȴ�.
     */
    private void OnDestroy()
    {
        print("OnDestroy �Լ� ȣ��");
    }
    #endregion

}
