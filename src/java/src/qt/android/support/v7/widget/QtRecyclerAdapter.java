package qt.android.support.v7.widget;

import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.content.Context;
import android.support.v7.widget.RecyclerView;

import java.lang.Integer;

public class QtRecyclerAdapter extends RecyclerView.Adapter<QtRecyclerAdapter.ViewHolder>
{
    public QtRecyclerAdapter(int count, long instance) {
        m_count = count;
        m_instance = instance;
    }

    // TODO: adapter.delegate?
    public static class ViewHolder extends RecyclerView.ViewHolder
    {
        public ViewHolder(TextView view) {
            super(view);
        }
        public void bind(CharSequence text) {
            TextView view = (TextView) itemView;
            if (view != null)
                view.setText(text);
        }
    }

    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        TextView view = new TextView(parent.getContext());
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(ViewHolder holder, int position) {
        holder.bind(Integer.toString(position));
    }

    @Override
    public int getItemCount() {
        return m_count;
    }

    public void setItemCount(int count) {
        if (m_count != count) {
            m_count = count;
            notifyDataSetChanged();
        }
    }

    private int m_count;
    private long m_instance;
}
